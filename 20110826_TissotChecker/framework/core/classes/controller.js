Controller = {
  getVar: function(key){
    if(typeof $(document).data('TissotControllerVar'+key) === 'undefined')
      return null;
    else
      return $(document).data('TissotControllerVar'+key);
  },
  setVar: function(key,obj){
    $(document).data('TissotControllerVar'+key,obj);
  },
  extendWith: function(obj){
    return $.extend(true, $.extend(true, {}, Controller), obj);
  }
};
