EffectHandler = function(){
  var self         = this;
  self._count      = 0;
  self._callback   = null;
  self.setCallback = function(cb){ self._callback = cb; };
  self.initialize  = function(){ self._count++; };
  self.finalize    = function(){
    if(--self._count == 0)
      self._callback();
  };
  return self;
};
