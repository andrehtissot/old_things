class String
  def camelize
    string = self.split('_').collect do |word|
      word.capitalize!
    end
    string.join
  end
end
