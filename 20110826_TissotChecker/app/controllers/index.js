IndexController = Controller.extendWith({
  initialize: function(){
    IndexController.maintainFullscreen();
  },
  enter: function(){
    IndexController.maintainFullscreen();
    location.href = ROOT_PATH+'#menu';
  }
});

IndexController.maintainFullscreen = function(){
  $('.ui-content').css('padding', '0px');
  $('.fullscreen').css({'height': $(window).height()+'px', 'width': $(window).width()+'px'});
  if(location.hash == '')
    setTimeout(IndexController.maintainFullscreen, 30);
};
