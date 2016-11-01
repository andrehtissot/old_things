String.prototype.extend = function(father, obj){
  if(typeof father.extendTo === 'undefined'){
    return Class.makeExtendable(father).extendTo(''+this, obj);
  } else {
    return father.extendTo(''+this, obj);
  }
};

Array.prototype.find = function(field, value){
  return $.grep(this, function(element){
      return element[field] == value;
  });
}

Class = function(){
  var self = this;
  self._class = Class;
  return self;
};
Class.type = 'Class';
Class.makeExtendable = function(klass_name){
  if($.type(father) != 'string')
    debug("Error: class cannot be extended because it's not string"); return null;
  return Class.extendTo(klass_name, eval(klass_name));
};

if(typeof Class.internal === 'object') { if(typeof Class.internal._automaticaly_add_to_list === 'undefined') { Class.internal._automaticaly_add_to_list = true; }
} else { Class.internal = { _automaticaly_add_to_list: true }; }

Class.extendTo = function(name, klass){
  constructor = function(){
    var self = this;
    self._class = eval(name);

    if(typeof self._superHasRan === 'undefined') self._superHasRan = false;

    self._super = function(){
      if(!(self._superHasRan)){
        if(arguments.length){
          //REVIEW
          debug('DANGER: review me');
          self = $.extend(true, self, $.extend(true, self._class._super.apply(new Object(), $.merge([],arguments)), self));
        }else{
          myAttributes = $.extend(true, new Object(), self);
          self = $.extend(true, $.extend(true, self, self._class._super.call(self)), myAttributes);
        }
        self._superHasRan = true;
      }
    };

    self.type = name;
    klass.constructor.apply(self, $.merge([self],arguments));
    self._super();
    delete self._superHasRan;
    self._class = eval(name);
    self.type = name;
    if(self._class.internal._automaticaly_add_to_list){
      self._class.all.push(self);
    }
    return self;
  };
  Klass = $.extend(true, $.extend(true, constructor, this), klass);
  Klass._super = this;
  Klass.type = name+'Class';
  Klass.all = [];
  Klass.first = function(){
    return (typeof Klass.all[0] !== 'undefined') ? Klass.all[0] : null;
  };
  Klass.last = function(){
    return Klass.all.length ? Klass.all[Klass.all.length-1] : null;
  };
  eval(name+' = Klass;');
  return Klass;
};
