GameEndedController = Controller.extendWith({
  initialize: function(){
    $('.restartGame').bind('tap', function(){
      IndexController.setVar('resetGame',true);
      $.mobile.changePage('#game');
    });
    $($(document.getElementById('game&game_ended')).find('.ui-icon-delete')).bind('tap', function(){
      wait_and_execute(function(){
        return location.hash == '#game';
      }, function(){
        $.mobile.changePage('#menu');
      }, 2);
      return false;
    });
  },
  enter: function(){
    winner = GameController.getVar('winnerTeam');
    if (winner) {
      $('#winnerTeamName').html(winner.name);
      $('#winnerTeamImage').attr('src', winner.image);
    }
    IndexController.setVar('menuChanged',true);
    IndexController.setVar('continueGame',false);
  },
  load: function(){
    $(document).bind('game_ended', function(){ TissotCore.openDialog('game&game_ended'); });
  }
});

