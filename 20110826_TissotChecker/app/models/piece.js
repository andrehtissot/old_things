Piece = function(team, house_x, house_y, options){
  if(typeof options === 'undefined') options = {};

  var self = this;
  self.isKing = false;
  self.team = team;
  self.x = function(){
    return Checkerboard.current.x-1+(2*(self.house_y%2 ? self.house_x : self.house_x+0.5)*(Checkerboard.current.piece_width+Checkerboard.current.line_width))+Checkerboard.current.line_width;
  };
  self.y = function(){
    return Checkerboard.current.y-1+(self.house_y*(Checkerboard.current.piece_width+Checkerboard.current.line_width))+Checkerboard.current.line_width;
  };
  self.house_x = house_x;
  self.house_y = house_y;
  self.dom = null;
  self.active = function(){
    return self.team == GameController.currentTeam();
  };
  self.html = function(additional_class){
    if(typeof additional_class === 'undefined') additional_class = '';
    special_class = 0
    if(self.isKing)
      special_class = 1
    if(!self.active())
      special_class += 2
    switch(special_class){
      case 1:
        special_class = 'game-piece-king '; break;
      case 2:
        special_class = 'game-piece-dark '; break;
      case 3:
        special_class = 'game-piece-dark-king '; break;
      default:
        special_class = '';
    }
    if(self.isSelected() && self.canIWalk()){
      special_class += 'game-piece-selected ';
    }
    return '<div class="game-piece '+special_class+additional_class+' game-piece-player-'+(self.team.shortname)+' game-square" style="top: '+self.y()+'px;left: '+self.x()+'px;z-index:2;"></div>';
  };
  self.canIWalk = function(){
    iCan = false;
    $.map(self.whereCanIGo(),function(value){
      if(value) iCan = true;
    });
    return iCan;
  };
  self.canIKillAgain = function(){
    iCan = false;
    $.map(self.whereCanIGo(),function(value, key){
      if(value && key[0] == 'k') iCan = true;
    });
    return iCan;
  };
  self.warning = function(){
    if(self.dom)
      $(self.dom).addClass('alert');
    setTimeout(function(){ $(self.dom).removeClass('alert'); }, 500);
  };
  self.updateLink = function(domObject){
    if(domObject){
      self.dom = domObject;
      $(self.dom).data('obj',self);
      $(self.dom).bind('tap',function(event){
        if(!GameController.blocked())
          $(this).data('obj').select();
      });
    }
  };
  self.isSelected = function(){
    return self == Piece.selected;
  };
  self.select = function(){
    if(!GameController.blocked()){
      GameController.block();
      if(self.active() && !self.isSelected() && !Piece.blockedSelection()){
        GameController.block();
        $(Piece.selected.dom).removeClass('game-piece-selected');
        Piece.selected.deselect();
        if(self.canIWalk()){
          Piece.selected = self;
          $(self.dom).addClass('game-piece-selected');
          $(document).one('gameghostshavevanished', function(){self.markTheWay(); GameController.unblock();});
        } else {
          $(document).one('gameghostshavevanished', function(){GameController.unblock();});
          GameController.unblock();
        }
        GameController.block();
        $(document).trigger('gamepiecewasclicked');
      }
      GameController.unblock();
    }
  };
  self.deselect = function(){
  };
  self.die = function(){
   self.hide();
   Piece.all = $.grep(Piece.all, function(value) {
     return value != self;
   });
   $(document).trigger('gamepiecehasdied');
  };
  self.hide = function(callback){
   if(self.dom){
     $(self.dom).animate({
       left: Math.floor(self.x() + Checkerboard.current.piece_width/2),
       top: Math.floor(self.y() + Checkerboard.current.piece_height/2),
       width: 0,
       height: 0,
       opacity: 0
     }, 240, callback);
   }
  };
  self.move = function(house_x, house_y, options){
    if(typeof options === 'undefined') options = {};
    GameController.block();
    self.house_x = house_x;
    self.house_y = house_y;
    $(self.dom).removeClass('game-piece-selected').animate({
      left: this.x(),
      top: this.y(),
    }, 300, function(){
      self.turnKing();
      self.clearInternalCache();
      if(typeof options['hasKilled'] !== 'undefined' && self.canIKillAgain()){
        Piece.blockSelection();
        $(document).trigger('gamepiecehasjustmoved');
        $(document).trigger('gamepiecehasmoved');
        $(document).trigger('gamebeginturn');
        self.markTheWay();
        $(document).trigger('gamepiececankillagain');
        GameController.unblock();
      } else {
        Piece.forceEndTurn();
      }
    });
  };
  self._whereCanIGo = null;
  self.whereCanIGo = function(){
   if(self._whereCanIGo){
    return self._whereCanIGo;
   } else {
    nw = ne   = ((self.isKing || !self.team.first()) && self.house_y != 0);
    knw = kne = ((self.isKing || !self.team.first()) && self.house_y > 1);
    sw = se   = ((self.isKing ||  self.team.first()) && self.house_y != 7);
    ksw = kse = ((self.isKing ||  self.team.first()) && self.house_y < 6);
    if(self.house_x == 3){
      kne = kse = false;
      if(self.house_y%2 == 0)
        se = ne = false;
    } else if(self.house_x == 0){
      knw = ksw = false;
      if(self.house_y%2)
        sw = nw = false;
    }

    if(nw){
      piece_in_the_way = Piece.findByLocation(self.house_x-(self.house_y%2) , self.house_y-1);
      if(piece_in_the_way){
        if(knw && piece_in_the_way.team != self.team && (Piece.findByLocation(self.house_x-1 , self.house_y-2) == null))
          knw = [self.house_x-1 , self.house_y-2];
        else
          knw = false;
        nw = false;
      } else {
        knw = false;
        nw = [self.house_x-(self.house_y%2) , self.house_y-1];
      }
    }
    if(ne){
      piece_in_the_way = Piece.findByLocation(self.house_x+(self.house_y%2 ? 0 : 1), self.house_y-1);
      if(piece_in_the_way){
        if(kne && piece_in_the_way.team != self.team && (Piece.findByLocation(self.house_x+1, self.house_y-2) == null))
          kne = [self.house_x+1, self.house_y-2];
        else
          kne = false;
        ne = false;
      } else {
        kne = false;
        ne = [self.house_x+(self.house_y%2 ? 0 : 1), self.house_y-1];
      }
    }
    if(sw){
      piece_in_the_way = Piece.findByLocation(self.house_x-(self.house_y%2) , self.house_y+1);
      if(piece_in_the_way){
        if(ksw && piece_in_the_way.team != self.team && (Piece.findByLocation(self.house_x-1 , self.house_y+2) == null)){
          ksw = [self.house_x-1 , self.house_y+2];
        }else{
          ksw = false;
        }
        sw = false;
      } else {
        ksw = false;
        sw = [self.house_x-(self.house_y%2) , self.house_y+1];
      }
    }
    if(se){
      piece_in_the_way = Piece.findByLocation(self.house_x+(self.house_y%2 ? 0 : 1), self.house_y+1);
      if(piece_in_the_way){
        if(kse && piece_in_the_way.team != self.team && (Piece.findByLocation(self.house_x+1, self.house_y+2) == null))
          kse = [self.house_x+1, self.house_y+2];
        else
          kse = false;
        se = false;
      } else {
        kse = false;
        se = [self.house_x+(self.house_y%2 ? 0 : 1), self.house_y+1];
      }
    }
    return self._whereCanIGo = {nw:nw,ne:ne,sw:sw,se:se,knw:knw,kne:kne,ksw:ksw,kse:kse};
   }
  };
  self.clearInternalCache = function(){
    self._whereCanIGo = null;
  };
  self.markTheWay = function(){
    GhostPiece.removeAll();
    if(Piece.blockedSelection()){
      $.map(self.whereCanIGo(),function(value, key){
        if(value && key[0] == 'k'){
          new GhostPiece(self, value[0], value[1], {'kill':true});
        }
      });
    } else {
      $.map(self.whereCanIGo(),function(value, key){
        if(value){
          new GhostPiece(self, value[0], value[1], (key[0] == 'k' ? {'kill':true} : {}));
        }
      });
    }
    GameController.redrawPieces();
  }
  self.turnKing = function(){
    if(!self.isKing && (
      ((!self.team.first()) && self.house_y == 0) ||
      (( self.team.first()) && self.house_y == 7)))
      self.isKing = true;
  };
  if(typeof options['dontRegister'] === 'undefined'){
    Piece.all.push(self);
  }
  return self;
};
Piece.draw = function(){
  html = '';
  $(Piece.all).each(function(){ 
    html += this.html();
  });
  return html;
};
Piece.clearCaches = function(){
  $(Piece.all).each(function(index){
    this.clearInternalCache();
  });
};
Piece.forceEndTurn = function(){
  if(Piece.blockedSelection())
    Piece.unblockSelection();
  $(document).trigger('gamepiecehasjustmoved');
  $(document).trigger('gameendturn');
  $(document).trigger('gamepiecehasmoved');
  Piece.deselect();
  $(document).trigger('gamebeginturn');
  while(GameController.blocked()){
    GameController.unblock();
  }
  while(Piece.blockedSelection()){
    Piece.unblockSelection();
  }
};
$(document).bind('gamebeginturn', function(){
  Piece.clearCaches();
  if(!Piece.canAnyoneWalk()){
    TissotCore.openDialog('game&game_is_tied');
  }
});
$(document).bind('gamepiecehasjustmoved', Piece.clearCaches);
Piece.linkToDom = function(){
  pieces = $('.game-piece');
  $(Piece.all).each(function(index){
    this.updateLink(pieces[index]);
  });
};
Piece.findByLocation = function(house_x, house_y){
  found = null;
  $(Piece.all).each(function(){
    if(this.house_y == house_y && this.house_x == house_x)
      found = this;
  });
  return found;
};
Piece.findByPosition = function(x, y){
  found = null;
  $(Piece.all).each(function(){
    if(this.x() == x && this.y() == y)
      found = this;
  });
  return found;
};
Piece.selected = {select:function(){}, deselect:function(){}};
Piece.deselect = function(){
  Piece.selected.deselect();
  Piece.selected = {select:function(){}, deselect:function(){}};
}
Piece.all = [];
Piece.clear = function(){
  Piece.deselect();
  Piece._blockedSelection = 0;
  Piece.all = [];
};
Piece._blockedSelection = 0;
Piece.blockSelection    = function(){ Piece._blockedSelection++; };
Piece.unblockSelection  = function(){ Piece._blockedSelection--; };
Piece.blockedSelection  = function(){ return Piece._blockedSelection != 0; };
Piece.canAnyoneWalk     = function(){ 
  can = false;
  $(Piece.all).each(function(){
    if(this.canIWalk()) can = true;
  });
  return can;
};
$(document).bind('gamepiecehasjustmoved', function(){ if(!Piece.blockedSelection()) Piece.deselect(); });
