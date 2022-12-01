# from: https://stackoverflow.com/questions/3264168/how-to-put-assertions-in-ruby-code

class AssertionError < RuntimeError; end

def assert &block
  raise AssertionError unless yield
end

def read_input_lines(input_file)
  open(input_file) { |file| file.readlines }
end
