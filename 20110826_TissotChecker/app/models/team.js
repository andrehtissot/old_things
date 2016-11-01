'Team'.extend(Model, {
  persist: ['victories'],
  constructor: function(self, name, shortname, image, spriteBase){
    self.id = shortname;
    self.name = name;
    self.spriteBase = spriteBase;
    self.image = image;
    self.shortname = shortname;
    self._pieces = null;
    self.victories = 0;
    self.sprite = function(){
      spriteSize = Team.spriteSizes[0];
      $(Team.spriteSizes).each(function(idx, size){
        if(size >= Checkerboard.current.piece_width){
          spriteSize = size;
        }
      });
      return spriteBase.replace('XXXXX', spriteSize);
    };
    self.pieces = function(){
      if(self._pieces)
        return self._pieces;

      return self._pieces = $.grep(Piece.all, function(value) { if(value.team == self) return value; });
    };
    self.style = function(){
      size = Checkerboard.current.piece_width+'px '+Checkerboard.current.piece_width*4+'px';
      return '.game-piece-player-'+self.shortname+'{background:url('+self.sprite()+') 0 0 no-repeat;-moz-background-size:'+size+';-webkit-background-size:'+size+';background-size:'+size+';}';
    };
    self.first = function(){
      return self == Team.first();
    };
    self.didIWon = function(){
      if(Team.all[self.first() ? 1 : 0].pieces().length == 0){
        Controller.setVar('winnerTeam', self);
        self.victories++;
        self.save();
        $(document).trigger('game_ended');
      }
    };
    self.myPiecesCanWalk = function(){
      howManyCan = 0;
      $(self.pieces()).each(function(){
        if(this.canIWalk()) howManyCan += 1;
      });
      if(howManyCan == 1) {
        $(self.pieces()).each(function(){
          if(this.canIWalk()) this.select();
        });
      }
      return (howManyCan > 0);
    };
  },
  _initialized: false,
  initialize: function(){
    if(!Team._initialized){
      Team._initialized = true;
      new Team('Firefox', 'ff', 'resources/firefox.png', 'resources/pieces/ff/XXXXX.jpg');
      new Team('Internet Explorer', 'ie', 'resources/ie.png', 'resources/pieces/ie/XXXXX.jpg');
    }
  },
  clear: function(){
    Team._initialized = false;
    Team.all = [];
  },
  spriteSizes: [128,116,104,92,80,68,56,44,32,20]
});
$(document).bind('gamebeginturn', function(){
  if((GameController.currentTeam().pieces() > 0) && !GameController.currentTeam().myPiecesCanWalk()){
    TissotCore.openDialog('game&you_are_trapped');
    Piece.forceEndTurn();
  }
});
$(document).bind('gamepiecehasdied', function(){
  $(Team.all).each(function(){
    this._pieces = null;
  });
});
