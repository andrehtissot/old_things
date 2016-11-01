'Model'.extend(Class, {
  persist: [],
  constructor: function(self){
    self.save = function(){
      if(self.id === null){
        debug('Id for a '+self.type+' was not defined');
      } else {
        if(Team.persist.length){
          attrs = $.map(self._class.persist, function(element){
            if(typeof self[element] !== 'undefined'){
              return "\""+element+"\":\""+escape(self[element])+"\"";
            }
          });
          jsonText = '{'+attrs.join(',')+'}';
          self._class.internal.addIndex(self.type, self.id);
          self._class.internal.setRecord(self.type, self.id, jsonText);
        }
      }
    };
    self.reload = function(){
      return self._class.internal.loadRecord(self, self.id);
    };
    wait_and_execute(function(){
        return (self.type != 'Model');
      }, function(){
        self.reload();
    });
  },
  load: function(id){
    return this.internal.loadRecord(new this(), id);
  },
  loadAll: function(options){
    if($.type(options) != 'object') options = {};
    dontUseList = ($.type(options.useList) == 'boolean' && options.useList == false);

    var self = this;
    automatic = self.internal._automaticaly_add_to_list;
    self.internal._automaticaly_add_to_list = false;
    obj = new self();
    self.internal._automaticaly_add_to_list = automatic;

    if(self.internal.recordIsAvailable(obj.type)){
      ids = localStorage.getItem('TissotModelPersistence'+obj.type);
      if(ids != null && ids.length){
        ids = ids.split(',');
        objs = $.map(ids, function(id){
          if(dontUseList){
            return self.internal.loadRecord(new self(), id);
          } else {
            obj = self.all.find('id', id)[0];
            if(obj) {
              return self.internal.loadRecord(obj, id);
            } else {
              return self.internal.loadRecord(new self(), id);
            }
          }
        });
        return objs;
      }
    }
    return [];
  },
  internal: {
    setRecord: function(type, id, value){
      if(id.match(/[^\da-zA-Z]/))
        debug('The id '+id+' is invalid');
      else
        localStorage.setItem('TissotModelPersistence'+type+id, value);
    },
    addIndex: function(type, id){
      if(id.match(/[^\da-zA-Z]/)){
        debug('The id '+id+' is invalid');
      }else{
        if(localStorage.getItem('TissotModelPersistence'+type)){
          previous = localStorage.getItem('TissotModelPersistence'+type);
          if((!(previous.indexOf(',') == -1 && previous == id)) &&
             (!(previous.indexOf(',') != previous.lastIndexOf(',') && previous.indexOf(','+id+',') != -1)) &&
             (!(previous.indexOf(',') == previous.lastIndexOf(',') && (previous.indexOf(','+id) != -1 || previous.indexOf(id+',') != -1))))
          localStorage.setItem('TissotModelPersistence'+type, localStorage.getItem('TissotModelPersistence'+type) + ','+id);
        }else{
          localStorage.setItem('TissotModelPersistence'+type, id);
        }
      }
    },
    recordIsAvailable: function(type){
      if(typeof localStorage.getItem('TissotModelPersistence'+type) === 'undefined' || localStorage.getItem('TissotModelPersistence'+type) == null){
        debug('localStorage is not available'); return false; } return true;
    },
    loadRecord: function(objBase, id){
      json = $.parseJSON(localStorage.getItem('TissotModelPersistence'+objBase.type+id));
      if(json){
        $.each(json, function(key, value){
          switch($.type(objBase[key])){
            case 'number':
              objBase[key] = parseFloat(value); break;
            default:
              objBase[key] = unescape(value);
          }
        });
        objBase.id = id;
        return objBase;
      } else {
        objBase.id = id;
        return objBase;
      }
    }
  }
});
