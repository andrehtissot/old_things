YouAreTrappedController = Controller.extendWith({
  enter: function(){
    $('#currentTeamName').html(GameController.currentTeam().name);
  }
});
