@_get_views_names
def get_views_names
  return @_get_views_names if @_get_views_names

  views = Dir.new("#{ROOT_PATH}app/views").to_a
  views.delete '.'
  views.delete '..'
  views.delete 'application'
  if views.include? 'index'
    views.delete 'index'
    views.unshift 'index'
  end
  @_get_views_names = views
  @_get_views_names.freeze
  views.each do |view|
    view.freeze
  end
  views
end

def get_subviews_for(view)
  subviews = Dir.new("#{ROOT_PATH}app/views/#{view}/").to_a
  subviews.delete '.'
  subviews.delete '..'
  subviews.collect! do |file|
    file if File.directory? "#{ROOT_PATH}app/views/#{view}/#{file}"
  end
  subviews.compact
end

def get_models
  models = Dir.new("#{ROOT_PATH}app/models").to_a
  models.delete '.'
  models.delete '..'
  models
end

def get_languages
  languages = Dir.new("#{ROOT_PATH}app/languages").to_a.collect do |lang|
    lang if lang.match /\.js$/
  end
  languages.compact
end

@_get_controllers 
def get_controllers()
  return @_get_controllers if @_get_controllers

  controllers = get_files_recursively("app/controllers/", /\.js$/)
  controllers.delete('application.js')
  controllers.compact!
  @_get_controllers  = controllers
  @_get_controllers.freeze
  controllers.each do |controller|
    controller.freeze
  end
  controllers
end

def get_controller_name_for(controller)
  if controller.match(/\/(.*)\.js/)
    controller.match(/\/(.*)\.js/)[1]
  else
    controller.gsub /\.js$/, ''
  end
end

def get_controller_event_name_for(controller)
  controller = controller.gsub(/\.js$/,'').gsub('/','&')
  return controller.gsub /&.*$/,'' if (controller.include?('&') && (controller.split('&')[-1] == controller.split('&')[-2]))
  controller
end

@_get_controllers_who_has_method = {}
def get_controllers_who_has_method method
  return @_get_controllers_who_has_method[method.to_sym] if @_get_controllers_who_has_method[method.to_sym]

  @_get_controllers_who_has_method[method.to_sym] 
  controllers = return_who_matches 'app/controllers/', get_controllers(), "[,\\s\\n\\t]#{method}\\s*:\\s*function\\s*\\(\\s*\\)\\s*\\{"
  @_get_controllers_who_has_method[method.to_sym] = controllers
  @_get_controllers_who_has_method[method.to_sym].freeze
  controllers.each do |controller|
    controller.freeze
  end
  controllers
end

@_get_views_who_has_css
def get_views_who_has_css
  return @_get_views_who_has_css if @_get_views_who_has_css

  views = get_files_recursively("app/views/", /\.css$/)
  views.delete 'application/application.css'
  @_get_views_who_has_css = views
  @_get_views_who_has_css.freeze
  views.each do |view|
    view.freeze
  end
  views
end

def get_controller_event_name_from_css(css)
  css = css.gsub(/\.css$/,'')
  if css.include? '/'
    (css = css.split('/')).pop
    return css.join '&'
  end
  css
end

