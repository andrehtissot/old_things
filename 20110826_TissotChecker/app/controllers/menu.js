MenuController = Controller.extendWith({
  initialize: function(){
    $(document).delegate('#MenuNewGameButtom', 'tap', function(){
      Controller.setVar('resetGame',true);
      $.mobile.changePage('#game');
      return false;
    });
  },  
  enter: function(){
    if(IndexController.getVar('menuChanged')){
      if(IndexController.getVar('continueGame')){
        $('#MenuContinueGameButtom').show();
      } else {
        $('#MenuContinueGameButtom').hide();
      }
    }
  }
});
