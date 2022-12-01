#!/usr/bin/env ruby

def usage
  puts "Usage: solve-01.rb <input_file>"
  exit
end

def import_frequency_changes_from(input_file)
  frequency_changes = []

  file_handler = open(input_file)
  file_handler.each { |line| frequency_changes << line.to_i }
  file_handler.close

  frequency_changes
end

def final_frequency(frequency_changes)
  frequency_changes.reduce(0, :+)
end

def duplicate_frequency(frequency_changes)
  totals = [0]
  total = 0

  frequency_changes.cycle.each do |x|
    total += x
    if totals.include? total
      break
    else
      totals.push(total)
    end
  end

  total
end

# MAIN

usage unless ARGV.size == 1

input_file = ARGV[0]
frequency_changes = import_frequency_changes_from(input_file)

puts "Final frequency: #{final_frequency(frequency_changes)}"
puts "First frequency reached twice: #{duplicate_frequency(frequency_changes)}"
