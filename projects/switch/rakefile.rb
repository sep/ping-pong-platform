PROJECT_CEEDLING_ROOT = "../vendor/ceedling"
load "#{PROJECT_CEEDLING_ROOT}/lib/rakefile.rb"

CLEAN.include("./build/artifacts/*.elf")

task :default => %w[ test:all ]

desc "build MSP430 code"
task :buildit2 do
	system "msp430-gcc -mmcu=msp430g2553 -O3 -I include -I ../communication/include mains/led_on/main.c src/led_driver.c -o out.elf"
end

desc "launches mspdebug for launchpad"
task :mspdebug do
	system "mspdebug rf2500"
end

namespace :build_mains do

	desc "build specified target application"
	task :* do
		puts "\t'build_mains:*' not specified, replace '*' with desired application to build"
	end
	
	def create_main_builds(mains)
		mains.map {|main|
			#desc "builds #{main} project"
			task main.to_sym do
				system "msp430-gcc -mmcu=msp430g2553 -O3 -I include -I ../communication/include
					mains/#{main}/main.c
					src/led_driver.c 
					-o ./build/artifacts/#{main}.elf"
			end
		}
		task :all => mains
	end
	
	create_main_builds(Dir.entries('./mains').select {|entry| File.directory? File.join('./mains',entry) and !(entry =='.' || entry == '..') })
	
end

desc "build all applications in mains"
task :build_mains => 'build_mains:all'
