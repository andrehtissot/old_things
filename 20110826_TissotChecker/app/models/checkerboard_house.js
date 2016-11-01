CheckerboardHouse = function(type, x, y){
  var self = this;
  self.x = x;
  self.y = y;
  self.type = type;
  self.html = function(){
    return '<div class="game-square game-square-'+self.type.order+'" style="top: '+self.y+'px;left: '+self.x+'px;"></div>';
  };
  CheckerboardHouse.all.push(self);
  return self;
};
CheckerboardHouse.clear = function(){
  CheckerboardHouse.all = [];
};
CheckerboardHouse.all = [];
