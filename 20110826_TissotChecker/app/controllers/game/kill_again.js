KillAgainController = Controller.extendWith({
  initialize: function(){
    $('#DontYouWantToKillAgainButtom').bind('tap', function(){
      $('#game .ui-content').unbind('tap.backgroundcheckerboard');
      Piece.deselect();
      Piece.forceEndTurn();
      TissotCore.closeDialog();
    });
  }
});
