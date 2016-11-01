OptionsController = Controller.extendWith({
  initialize: function(){
    if(localStorage.getItem('Language')){
      $('#option-language-'+localStorage.getItem('Language')+'-label').click();
    } else {
      $('#option-language-en-label').click();
    }
    
    $(document).delegate('[name=option-language]', 'change', function(){
      lang = $(this).data('val');
      localStorage.setItem('Language',lang);
      TissotCore.translatePages(lang);
      delete lang;
    });
  }
});
