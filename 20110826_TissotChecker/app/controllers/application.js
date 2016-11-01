var ROOT_PATH = location.href.replace(/#.*$/,'');

wait_and_execute = function(when, what, interval){
  if(typeof interval === 'undefined') interval = 100;

  if (when()){
    what();
  } else {
    setTimeout(wait_and_execute, interval, when, what);
  }
};

debug = function(msg){
  if(console.log)
    console.log(msg);
};

TissotCore.translatePages = function(idiom){
  if(typeof idiom == 'undefined'){
    if(typeof localStorage.getItem('Language') === 'undefined' || localStorage.getItem('Language') == null || TissotCore.Language[localStorage.getItem('Language')] == null){
      L = TissotCore.Language.en;
    } else {
      L = TissotCore.Language[localStorage.getItem('Language')];
    }
  } else {
    L = TissotCore.Language[idiom];
  }
  $(':jqmData(translate)').each(function(){
    $(this).html(L[$(this).data('translate')]);
  });
};

$(document).one('pagebeforeshow', function(){
  TissotCore.translatePages();
});

TissotCore.camelize = function(word, options){
  if(typeof options === 'undefined') options = {};

  words = word.split(' ');
  if(typeof options['spaces'] !== 'undefined') 
    spaces = options['spaces'];
  else
    spaces = 1;

  word = [];
 
  $(words).each(function(){
    if(this.length > 0){
      word.push(this[0].toUpperCase()+this.substr(1));
    }
  });

  space = '';
  for(c=0;c<spaces;c++){
    space += ' ';
  }
  return word.join(space);
};

TissotCore.getControllerName = function(name){
  name = name.replace(/\.js$/,'');
  if(name.match(/&(.*)$/)){
    name = name.match(/&(.*)$/)[1];
    name = name.replace('_',' ');
  }
  return TissotCore.camelize(name,{spaces: 0});
};

TissotCore.openDialog = function(view){
  $('<a href="#'+view+'" data-rel="dialog"/>').click();
  $(document).trigger('pagebeforeshow_'+view);
};

TissotCore.closeDialog = function(){
  $('.ui-dialog').dialog('close');
};
