#!/usr/bin/env ruby

require_relative "../utils.rb"

input_file = "../../data/2019/02.txt"

input = read_input_lines(input_file).first.split(",").map(&:to_i)

def compute(programme)
  new_programme = programme.dup

  index = 0
  opcode = new_programme[index]

  while opcode != 99
    position_1 = new_programme[index + 1]
    position_2 = new_programme[index + 2]
    position_3 = new_programme[index + 3]

    case opcode
    when 1
      new_programme[position_3] = new_programme[position_1] + new_programme[position_2]
    when 2
      new_programme[position_3] = new_programme[position_1] * new_programme[position_2]
    end

    index += 4
    opcode = new_programme[index]
  end

  new_programme
end

assert { compute([1,0,0,0,99]) == [2,0,0,0,99] }
assert { compute([2,3,0,3,99]) == [2,3,0,6,99] }
assert { compute([2,4,4,5,99,0]) == [2,4,4,5,99,9801] }
assert { compute([1,1,1,4,99,5,6,0,99]) == [30,1,1,4,2,5,6,0,99] }
assert do
  compute([1, 9, 10, 3, 2, 3, 11, 0, 99, 30, 40, 50]) ==
    [3500, 9, 10, 70, 2, 3, 11, 0, 99, 30, 40, 50]
end

modified_input = input.dup
modified_input[1] = 12
modified_input[2] = 2

puts "Programme alarm: #{compute(modified_input)[0]}"

target = 19690720

(0..99).each do |noun|
  (0..99).each do |verb|
    modified_input = input.dup
    modified_input[1] = noun
    modified_input[2] = verb

    if compute(modified_input)[0] == target
      puts "100 * noun + verb = #{100 * noun + verb}"
      exit 0
    end
  end
end
