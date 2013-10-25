PROJECT_CEEDLING_ROOT = "../vendor/ceedling"
load "#{PROJECT_CEEDLING_ROOT}/lib/rakefile.rb"

task :default => %w[ test:all ]

desc "build MSP430 code"
task :buildit do
	system "msp430-gcc -mmcu=msp430g2553 -O3 -I include -I ../communication/include src/led_driver.c -o out.elf"
end

desc "launches mspdebug for launchpad"
task :mspdebug do
	system "mspdebug rf2500"
end
