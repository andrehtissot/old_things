ScoreController = Controller.extendWith({
  initialize: function(){
    Team.initialize()
    $(Team.all).each(function(){
      $('#'+this.shortname+'-score-count').html('0');
    });
    setTimeout(function(){
      $(Team.all).each(function(){
        $('#'+this.shortname+'-score-count').html(this.victories);
      });
    }, 200);
  },
  enter: function(){
    $(Team.all).each(function(){
      $('#'+this.shortname+'-score-count').html(this.victories);
    });
  }
});
