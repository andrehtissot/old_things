GameIsTiedController = Controller.extendWith({
  initialize: function(){
    $('.restartGame').bind('tap', function(){
      Controller.setVar('resetGame',true);
      $.mobile.changePage('#game');
    });
    $($(document.getElementById('game&game_is_tied')).find('.ui-icon-delete')).bind('tap', function(){
      wait_and_execute(function(){
        return location.hash == '#game';
      }, function(){
        $.mobile.changePage('#menu');
      }, 2);
      return false;
    });
  }
});
