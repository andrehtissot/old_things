# ^ Removing older js's
FileUtils.rm Dir.glob("#{ROOT_PATH}build/*.js")
# Removing older js's $

# ^ Mount JavaScript file
# ^ Mount JavaScript file -> First Part
# ^ Mount JavaScript file -> First Part -> jquery
FileUtils.cp "#{ROOT_PATH}framework/libs/jquery.js","#{ROOT_PATH}build/jquery.js.tmp"
remove_comment_js 'build/jquery.js.tmp'
# Mount JavaScript file -> First Part -> jquery $

# ^ Mount JavaScript file -> First Part -> Language
append_at_end_of_file 'build/index.js', "\nTissotCore = { Language : {\n"
last_lang = (languages = get_languages).pop
languages.each do |lang|
  append_at_end_of_file2 "build/index.js", "app/languages/#{lang}", :text_after => ','
end
append_at_end_of_file2 "build/index.js", "app/languages/#{last_lang}", :text_after => "}};\n"
# Mount JavaScript file -> First Part -> Language $

# Mount JavaScript file -> First Part -> Core Class Definitions
get_files_recursively('framework/core/classes/', /\.js$/).sort.each do |klass|
  append_at_end_of_file2 "build/index.js", "framework/core/classes/#{klass}"
end
# $ Mount JavaScript file -> Core Class Definitions

# ^ Mount JavaScript file -> First Part -> Models
get_models.each do |model|
  append_at_end_of_file2 'build/index.js', "app/models/#{model}" if(model.match /\.js$/)
end
# Mount JavaScript file -> First Part -> Models $

# ^ Mount JavaScript file -> First Part -> Application Script
append_at_end_of_file2 "build/index.js", 'app/controllers/application.js', :text_after => "\n"
# Mount JavaScript file -> First Part -> Application Script $

# ^ Mount JavaScript file -> First Part -> Router
append_at_end_of_file 'build/index.js', "
$(document).bind('pagebeforeshow', function(){
  if (location.hash){
    $(document).trigger('pagebeforeshow_'+location.hash.substr(1));"+
(get_views_names.include?('index') ? "\n}else{$(document).trigger('pagebeforeshow_index');" : '')+"
  }
});\n"
# Mount JavaScript file -> First Part -> Router  $

# ^ Mount JavaScript file -> First Part -> Controllers -> load method
if get_controllers_who_has_method('load').size > 0
  append_at_end_of_file  'build/index.js', "$(document).one('pagecreate',function(){\n";
  get_controllers_who_has_method('load').each do |controller|
    append_at_end_of_file  'build/index.js', "#{get_controller_name_for(controller).camelize}Controller.load();\n";
  end
  append_at_end_of_file  'build/index.js', "});\n";
end
# Mount JavaScript file -> First Part -> Controllers -> load method $

# ^ Mount JavaScript file -> First Part -> Compacting First Part
remove_comment_js 'build/index.js'
minify_js 'build/index.js'
append_at_end_of_file2 'build/jquery.js.tmp', 'build/index.js'
FileUtils.rm "#{ROOT_PATH}build/index.js"
FileUtils.mv "#{ROOT_PATH}build/jquery.js.tmp", "#{ROOT_PATH}build/first_part.js.tmp"
# Mount JavaScript file -> First Part -> Compacting First Part $
# Mount JavaScript file -> First Part $

# ^ Mount JavaScript file -> Second Part
# ^ Mount JavaScript file -> Second Part -> jquery mobile
FileUtils.cp "#{ROOT_PATH}framework/libs/jquery.mobile.js", "#{ROOT_PATH}build/jquery.mobile.js.tmp"
remove_comment_js 'build/jquery.mobile.js.tmp'
# Mount JavaScript file -> Second Part -> jquery mobile $

# ^ Mount JavaScript file -> Second Part -> CSS
get_views_who_has_css.each do |css|
  append_at_end_of_file "build/index.js", "$(document).bind('pagebeforeshow_#{get_controller_event_name_from_css(css)}',function(){$('#tissot_especific_style').html(\"<style>"
  encapsulate_css_in_js2 "app/views/#{css}", "build/index.css.tmp"
  append_at_end_of_file2 "build/index.js", "build/index.css.tmp"
  FileUtils.rm "#{ROOT_PATH}build/index.css.tmp"
  append_at_end_of_file "build/index.js", "</style>\");});\n"
end
# Mount JavaScript file -> Second Part -> CSS $

# ^ Mount JavaScript file -> Second Part -> Controllers
get_controllers.each do |controller|
  append_at_end_of_file2 'build/index.js', "app/controllers/#{controller}"
end

# ^ Mount JavaScript file -> Second Part -> Controllers -> initialize method
get_controllers_who_has_method('initialize').each do |controller|
  append_at_end_of_file  'build/index.js', "$(document).one('pagebeforeshow_#{get_controller_event_name_for(controller)}',function(){#{get_controller_name_for(controller).camelize}Controller.initialize();});\n"
end
# Mount JavaScript file -> Second Part -> Controllers -> initialize method $

# ^ Mount JavaScript file -> Second Part -> Controllers -> enter method
get_controllers_who_has_method('enter').each do |controller|
  append_at_end_of_file  'build/index.js', "$(document).bind('pagebeforeshow_#{get_controller_event_name_for(controller)}',function(){#{get_controller_name_for(controller).camelize}Controller.enter();});\n"
end
# Mount JavaScript file -> Second Part -> Controllers -> enter method $
# Mount JavaScript file -> Second Part -> Controllers $

# ^ Mount JavaScript file -> Second Part -> Compacting Second Part
remove_comment_js 'build/index.js'
minify_js 'build/index.js'
append_at_end_of_file2 'build/jquery.mobile.js.tmp', 'build/index.js'
FileUtils.rm "#{ROOT_PATH}build/index.js"
FileUtils.mv "#{ROOT_PATH}build/jquery.mobile.js.tmp", "#{ROOT_PATH}build/second_part.js.tmp"
# Mount JavaScript file -> Second Part -> Compacting Second Part $

# ^ Mount JavaScript file -> Joining files
FileUtils.mv "#{ROOT_PATH}build/first_part.js.tmp", "#{ROOT_PATH}build/index.js"
append_at_end_of_file2 'build/index.js', 'build/second_part.js.tmp'
FileUtils.rm 'build/second_part.js.tmp'
# Mount JavaScript file -> Joining files $
# Mount JavaScript file $
