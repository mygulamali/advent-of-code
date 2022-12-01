#!/usr/bin/env ruby

require_relative "../utils.rb"

input_file = "../../data/2019/01.txt"

masses = read_input_lines(input_file).map { |line| line.to_i }

def fuel_for_mass(mass)
  (mass / 3.0).floor - 2
end

def total_fuel(masses)
  masses.map { |mass| fuel_for_mass(mass) }.reduce(0, :+)
end

def fuel_for_mass_with_fuel(mass, total = 0)
  fuel = fuel_for_mass(mass)

  if fuel >= 0
    total += fuel + fuel_for_mass_with_fuel(fuel, total)
  else
    total
  end
end

def total_fuel_with_fuel(masses)
  masses.map { |mass| fuel_for_mass_with_fuel(mass) }.reduce(0, :+)
end

assert { fuel_for_mass_with_fuel(14) == 2 }
assert { fuel_for_mass_with_fuel(1969) == 966 }
assert { fuel_for_mass_with_fuel(100756) == 50346 }

puts "Total fuel required: #{total_fuel(masses)}"
puts "Total fuel with fuel required: #{total_fuel_with_fuel(masses)}"
