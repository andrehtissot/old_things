GhostPiece = function(piece, house_x, house_y, options){
  if(typeof options !== 'object')
    options = {};

  var self = $.extend(true, new Piece(piece.team, house_x, house_y, {dontRegister:true}),{
    house_x:house_x,
    house_y:house_y,
    isKing:piece.isKing,
    active:function(){
      return true;
    },
    isSelected:function(){
      return false;
    },
    select:function(){
      if(!GameController.blocked()){
        GameController.block();
        if(self.isKiller){
          Piece.blockSelection();
          $('#game .ui-content').unbind('tap.backgroundcheckerboard');
          self.kill();
          self.master.move(self.house_x, self.house_y, {hasKilled:true});
          Piece.unblockSelection();
        } else {
          self.master.move(self.house_x, self.house_y);
        }
        self.hideOtherGhosts();
        self.team.didIWon();
        GameController.unblock();
      }
    }
  });
  self.master = piece;
  self.isKiller = (options['kill']) ? true : false;
  self.kill = function(){
    piece = Piece.findByLocation(self.master.house_x + ((self.master.house_x < self.house_x) ? (self.house_y%2 ? 0 : 1) : (self.house_y%2 ? -1 : 0)), (self.house_y+self.master.house_y)/2);
    if(piece != null) piece.die();
  };
  self.hideOtherGhosts = function(){
    GameController.block();
    $(GhostPiece.all).each(function(){
      if(this != self)
        this.hide();
    });
    GameController.unblock();
  };
  GhostPiece.all.push(self);
  return self;
};
GhostPiece.draw = function(){
  html = '';
  $(GhostPiece.all).each(function(){ 
    html += this.html('game-piece-ghost');
  });
  return html;
};
GhostPiece.linkToDom = function(){
  ghosts = $('.game-piece-ghost');
  $(GhostPiece.all).each(function(index){
    this.updateLink(ghosts[index]);
  });
};
GhostPiece.iniEfect = function(){
  $(GhostPiece.all).each(function(index){
    GameController.block();
    if(this.dom){
      $(this.dom).css({left:this.master.x(),top:this.master.y()}).animate({
        left: this.x(),
        top: this.y(),
        opacity: 0.33
      }, 300, function(){
        GameController.unblock();
      });
    }
  });
  GameController.unblock();
};
$(document).bind('gamedrawn',GhostPiece.iniEfect);
GhostPiece.removeAll = function(){
  GhostPiece.all = [];
};
$(document).bind('gamepiecehasmoved', GhostPiece.removeAll);
GhostPiece.all = [];
GhostPiece.hideAll = function(){
 GameController.block();
 if(GhostPiece.all.length > 0) {
   effect_handler = new EffectHandler();
   effect_handler.setCallback(function(){$(document).trigger('gameghostshavevanished');GameController.unblock();});
   $(GhostPiece.all).each(function(){
     effect_handler.initialize();
     this.hide(effect_handler.finalize);
   });
 } else {
   $(document).trigger('gameghostshavevanished');
   GameController.unblock();
 }
};
GhostPiece.clear = function(){
  GhostPiece.removeAll();
};
$(document).bind('gamepiecewasclicked', GhostPiece.hideAll);
