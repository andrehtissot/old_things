GameController = $.extend(true, $.extend(true, GameController, {
  initialize: function(){
    wait_and_execute(function(){
      return (($('.ui-content').length > 0) && ($('.fullscreen').length > 0));
    },function(){
      GameController.initializeObjects();
      GameController.prepareGameField();


      GameController.playerTwoTapped = 0;
      $('#playerTwo').bind('tap', function(){
        if(++GameController.playerTwoTapped == 3){
          GameController.playerTwoTapped = 0;
          Controller.setVar('winnerTeam', Team.last());
          Team.last().victories++;
          Team.last().save();
          $(document).trigger('game_ended');
        }
      });
      GameController.playerOneTapped = 0;
      $('#playerOne').bind('tap', function(){
        if(++GameController.playerOneTapped == 3){
          GameController.playerOneTapped = 0;
          Controller.setVar('winnerTeam', Team.first());
          Team.first().victories++;
          Team.first().save();
          $(document).trigger('game_ended');
        }
      });
      

    });
  },
  enter: function(){
    if(GameController.getVar('resetGame')){
      $('#checkerboard').css('visibility', 'hidden');
      GameController.setVar('resetGame',false);
      GameController.clearInitialObjects();
      GameController.initializeObjects();
      $(document).one('pageshow',function(){GameController.prepareGameField();$('#checkerboard').css('visibility', '');});
    } else {
      $(document).one('pageshow',function(){$('#checkerboard').css('visibility', '');});
    }
    $(document).one('pagebeforehide',function(){GameController.prepareGameField();$('#checkerboard').css('visibility', 'hidden');});
    GameController.setVar('menuChanged',true);
    GameController.setVar('continueGame',true);
  }
}, Controller));
