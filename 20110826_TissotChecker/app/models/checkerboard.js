Checkerboard = function(name){
  var self = this;
  self.name = name;
  self.piece_width = 0;
  self.piece_height = 0;
  self.style = function(){
    return '.game-square{width: '+self.piece_width+'px;height: '+self.piece_height+'px;}';
  };
  Checkerboard.all.push(self);
  Checkerboard.current = self;
  return self;
};
Checkerboard.clear = function(){
  Checkerboard.current = null;
  Checkerboard.all = [];
};
Checkerboard.all = [];
Checkerboard.current;
Checkerboard.selectBackgroundCheckerboard = function(){
  if(!GameController.blocked()){
    TissotCore.openDialog('game&kill_again');
  }
};
$(document).bind('gamepiececankillagain', function(){
  $('#game .ui-content').bind('tap.backgroundcheckerboard', Checkerboard.selectBackgroundCheckerboard);
});
