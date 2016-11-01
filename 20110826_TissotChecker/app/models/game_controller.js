GameController = {
  currentTeam: function(){
    if(GameController._currentTeam)
      return GameController._currentTeam;
    else
      if(Team.all.length)
        return GameController._currentTeam = Team.all[(GameController.currentTeamIndex = Math.floor(Math.random()*2))];
      else
        debug('GameController.currentTeam: no team has been created');
  },
  currentTeamIndex: null,
  changeTeam: function(){
    GameController._currentTeam = Team.all[GameController.currentTeamIndex = (GameController.currentTeamIndex==0 ? 1 : 0)];
  },
  _currentTeam: null,
  prepareGameField: function(){
    checkerboard = Checkerboard.current;

    player_title_height = 25;
    back_buttom_height =  40;

    checkerboard.max_height = checkerboard.max_broadness = $(window).height() - back_buttom_height - player_title_height*2;
    checkerboard.line_width = 2;

    checkerboard.piece_height = checkerboard.piece_width = Math.floor(($(window).width() - (9*checkerboard.line_width)) / 8);
    checkerboard.broadness = (checkerboard.piece_width * 8) + (9*checkerboard.line_width);
    if (checkerboard.broadness > checkerboard.max_broadness){
      checkerboard.broadness = checkerboard.max_broadness;
      checkerboard.piece_height = checkerboard.piece_width = Math.floor((checkerboard.max_broadness - (9*checkerboard.line_width)) / 8);
    }

    checkerboard.broadness = (checkerboard.piece_width * 8) + (9*checkerboard.line_width);

    checkerboard.x = 1+Math.ceil(($(window).width() - checkerboard.broadness) / 2);
    checkerboard.y = player_title_height + Math.floor((checkerboard.max_height - checkerboard.broadness) / 2);

    blackHouseType = CheckerboardHouseType.all[0];
    whiteHouseType = CheckerboardHouseType.all[1];

    html = '<style>'+CheckerboardHouseType.all[0].style()+"\n"+CheckerboardHouseType.all[1].style()+"\n"+checkerboard.style()+"\n"+Team.all[0].style()+"\n"+Team.all[1].style()+'</style>';

    first = true;
    for(counttop = 0; counttop < 8; counttop++){
      for(countleft = 0; countleft < 8; countleft++){
        type = (first) ? whiteHouseType : blackHouseType;
        html += (new CheckerboardHouse(type, checkerboard.x-1+(countleft*(checkerboard.piece_width+checkerboard.line_width))+checkerboard.line_width, checkerboard.y-1+(counttop*(checkerboard.piece_width+checkerboard.line_width))+checkerboard.line_width)).html();
        first = !first;
      }
      first = !first;
    }

    html += '<div id="checkerboard-pieces">'+Piece.draw() + GhostPiece.draw()+'</div>';
    $("#checkerboard").replaceWith('<div id="checkerboard" style="left:'+(checkerboard.x-checkerboard.line_width+1)+'px;top:'+(checkerboard.y-checkerboard.line_width+1)+'px;width:'+(checkerboard.broadness-checkerboard.line_width*2)+'px;height:'+(checkerboard.broadness-checkerboard.line_width*2)+'px;background-color:#000">'+html+'</div>');

    Piece.linkToDom();
    GhostPiece.linkToDom();

    $(window).one('resize', GameController.prepareGameField);
    $(document).one('orientationchange', GameController.prepareGameField);
  },
  redrawPieces: function(){
    GameController.prepareGameField();
    $(document).trigger('gamedrawn');
  },
  initializeObjects: function(){
    Team.initialize();
    first     = Team.first();
    second    = Team.last();

    checkerboard = new Checkerboard('traditional');
    new CheckerboardHouseType('black', 'resources/black_house.png');
    new CheckerboardHouseType('white', 'resources/white_house.png');

    checkerboard = new Checkerboard('traditional');

    for(count_x = 0; count_x < 4; count_x++){
      for(count_y = 0; count_y < 3; count_y++){
        new Piece(first, count_x, count_y);
      }
      for(count_y = 5; count_y < 8; count_y++){
        new Piece(second, count_x, count_y);
      }
    }
  },
  clearInitialObjects: function(){
    Team.clear();
    GhostPiece.clear();
    Checkerboard.clear();
    Piece.clear();
    Checkerboard.clear();
    CheckerboardHouseType.clear();
    CheckerboardHouse.clear();
    GameController.clear();
  },
  _block: 0,
  block: function(){ GameController._block++; },
  unblock: function(){ GameController._block--; },
  blocked: function(){ return GameController._block != 0; }
};
GameController.clear = function(){
  GameController.currentTeamIndex = null;
  GameController._currentTeam     = null;
  GameController._block           = 0;
};
$(document).bind('gameendturn', GameController.changeTeam);
$(document).bind('gamebeginturn', GameController.redrawPieces);
