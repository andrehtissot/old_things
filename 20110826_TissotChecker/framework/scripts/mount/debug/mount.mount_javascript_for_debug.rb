# ^ Removing older js's
FileUtils.rm_f Dir.glob("#{ROOT_PATH}build/*.js")
# Removing older js's $

# ^ Mount JavaScript file
javascript_files_counter = 0
# ^ Mount HTML file -> puts jquery to load
FileUtils.touch "#{ROOT_PATH}build/index.js"
prepend1 'build/index.htm', '<script type="text/javascript" src="resources/jquery.js"></script>', '<script', :max => 1
# Mount HTML file -> puts jquery to load $

# ^ Mount JavaScript file -> Language
append_at_end_of_file 'build/index.js', "\nTissotCore = { Language : {\n"
last_lang = (languages = get_languages).pop
languages.each do |lang|
  append_at_end_of_file2 "build/index.js", "app/languages/#{lang}", :text_after => ','
end
append_at_end_of_file2 "build/index.js", "app/languages/#{last_lang}", :text_after => "}};\n"
# Mount JavaScript file -> Language $

# Mount JavaScript file -> Core Class Definitions
get_files_recursively('framework/core/classes/', /\.js$/).sort.each do |klass|
  append_at_end_of_file2 "build/index.js", "framework/core/classes/#{klass}"
end
# $ Mount JavaScript file -> Core Class Definitions

# ^ Mount JavaScript file -> Models
javascript_files_counter+=1
get_models.each do |model|
  append_at_end_of_file2 "build/index#{javascript_files_counter}.js", "app/models/#{model}" if(model.match /\.js$/)
end
append1 'build/index.htm', "\n<script type=\"text/javascript\" src=\"index#{javascript_files_counter}.js\"></script>", '</script>', :max => 1, :skip => javascript_files_counter+1
# Mount JavaScript file -> Models $

# ^ Mount JavaScript file -> Application Script
append_at_end_of_file2 "build/index#{javascript_files_counter+1}.js", 'app/controllers/application.js', :text_after => "\n"
# Mount JavaScript file -> Application Script $

# ^ Mount JavaScript file -> Router
append_at_end_of_file "build/index#{javascript_files_counter+=1}.js", "
$(document).bind('pagebeforeshow', function(){
  if (location.hash){
    $(document).trigger('pagebeforeshow_'+location.hash.substr(1));"+
(get_views_names.include?('index') ? "\n}else{$(document).trigger('pagebeforeshow_index');" : '')+"
  }
});\n"

append1 'build/index.htm', "<script type=\"text/javascript\" src=\"index#{javascript_files_counter}.js\"></script>", '</script>', :max => 1, :skip => javascript_files_counter+1
# Mount JavaScript file -> Router  $

# ^ Mount JavaScript file -> Controllers -> load method
if get_controllers_who_has_method('load').size > 0
  append_at_end_of_file  'build/index.js', "$(document).one('pagecreate',function(){\n";
  get_controllers_who_has_method('load').each do |controller|
    append_at_end_of_file  'build/index.js', "#{get_controller_name_for(controller).camelize}Controller.load();\n";
  end
  append_at_end_of_file  'build/index.js', "});\n";
end
# Mount JavaScript file -> Controllers -> load method $

# ^ Mount HTML file -> puts jquery mobile to load
prepend1 'build/index.htm', '<script type="text/javascript" src="resources/jquery.mobile.js"></script>', '</head', :max => 1

# ^ Mount JavaScript file -> CSS
javascript_files_counter+=1
get_views_who_has_css.each do |css|
  append_at_end_of_file "build/index#{javascript_files_counter}.js", "$(document).bind('pagebeforeshow_#{get_controller_event_name_from_css(css)}',function(){$('#tissot_especific_style').html(\"<style>"
  encapsulate_css_in_js2 "app/views/#{css}", "build/index.css.tmp"
  append_at_end_of_file2 "build/index#{javascript_files_counter}.js", "build/index.css.tmp"
  FileUtils.rm "#{ROOT_PATH}build/index.css.tmp"
  append_at_end_of_file "build/index#{javascript_files_counter}.js", "</style>\");});\n"
end
# Mount JavaScript file -> CSS $

# ^ Mount JavaScript file -> Controllers
get_controllers.each do |controller|
  append_at_end_of_file2 "build/index#{javascript_files_counter}.js", "app/controllers/#{controller}"
end

# ^ Mount JavaScript file -> Controllers -> initialize method
get_controllers_who_has_method('initialize').each do |controller|
  append_at_end_of_file  "build/index#{javascript_files_counter}.js", "$(document).one('pagebeforeshow_#{get_controller_event_name_for(controller)}',function(){#{get_controller_name_for(controller).camelize}Controller.initialize();});\n"
end
# Mount JavaScript file -> Controllers -> initialize method $

# ^ Mount JavaScript file -> Controllers -> enter method
get_controllers_who_has_method('enter').each do |controller|
  append_at_end_of_file  "build/index#{javascript_files_counter}.js", "$(document).bind('pagebeforeshow_#{get_controller_event_name_for(controller)}',function(){#{get_controller_name_for(controller).camelize}Controller.enter();});\n"
end
# Mount JavaScript file -> Controllers -> enter method $
# Mount JavaScript file -> Controllers $

append1 'build/index.htm', "<script type=\"text/javascript\" src=\"index#{javascript_files_counter}.js\"></script>", '</script>', :max => 1, :skip => javascript_files_counter+1
# Mount JavaScript file $

