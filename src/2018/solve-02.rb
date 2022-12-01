#!/usr/bin/env ruby

def usage
  puts "Usage: solve-02.rb <input_file>"
  exit
end

def import_ids_from(input_file)
  ids = []

  file_handler = open(input_file)
  file_handler.each { |line| ids << line }
  file_handler.close

  ids
end

def checksum(ids)
  two_times = 0
  three_times = 0

  ids.each do |id|
    chars = id.chars.uniq

    two = 0
    three = 0

    chars.each do |char|
      n = id.count(char)
      if n == 2
        two = 1
      elsif n == 3
        three = 1
      end
    end

    two_times += two
    three_times += three
  end

  two_times * three_times
end

def common_letters(ids)
  id = ""

  ids.each do |id_1|
    ids.each do |id_2|
      next if id_1 == id_2

      chars_1 = id_1.chars
      chars_2 = id_2.chars

      bit_diff = ("1" * chars_1.size).chars.map(&:to_i)

      bit_diff.each_with_index do |bit, index|
        if chars_1[index] == chars_2[index]
          bit_diff[index] = 0
        end
      end

      if bit_diff.reduce(&:+) == 1
        index = bit_diff.find_index(1)
        chars_1.delete_at(index)
        id = chars_1.join
      end
    end
  end

  id
end

# MAIN

usage unless ARGV.size == 1

input_file = ARGV[0]
ids = import_ids_from(input_file)

# test IDs for checksum, answer should be 12
# ids = [
#   "abcdef",
#   "bababc",
#   "abbcde",
#   "abcccd",
#   "aabcdd",
#   "abcdee",
#   "ababab",
# ]

puts "Checksum: #{checksum(ids)}"

# test IDs for common_letters, answer should be "fgij"
# ids = [
#   "abcde",
#   "fghij",
#   "klmno",
#   "pqrst",
#   "fguij",
#   "axcye",
#   "wvxyz",
# ]

puts "Common letters: #{common_letters(ids)}"
