CheckerboardHouseType = function(name, path){
  var self = this;
  self.name = name;
  self.order = CheckerboardHouseType.order;
  self.path = path;
  self.style = function(){
    size = Checkerboard.current.piece_width+'px '+Checkerboard.current.piece_width+'px';
    return '.game-square-'+self.order+'{background:url('+self.path+') 0 0 no-repeat; -moz-background-size:'+size+'; -webkit-background-size:'+size+'; background-size:'+size+';z-index:0;}';
  };
  CheckerboardHouseType.all.push(self);
  CheckerboardHouseType.order++;
  return self;
};
CheckerboardHouseType.clear = function(){
  CheckerboardHouseType.all = [];
  CheckerboardHouseType.order = 0;
};
CheckerboardHouseType.all = [];
CheckerboardHouseType.order = 0;
