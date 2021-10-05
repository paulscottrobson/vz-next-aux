# *****************************************************************************
# *****************************************************************************
#
#		Name:		export.rb
#		Author:		Paul Robson (paul@robsons.org.uk)
#		Date:		30th September 2021
#		Reviewed: 	No
#		Purpose:	Export ROM image
#
# *****************************************************************************
# *****************************************************************************

# *****************************************************************************
#
#  					Class encapsulating standard ROM
#
# *****************************************************************************

class StandardROM
	def initialize(binary_file)
		@data = open(binary_file,"rb").each_byte.collect { |a| a }
	end 

	def export_include(include_file)
		bytes = @data.collect { |b| b.to_s }.join(",")
		open(include_file,"w").write(bytes+"\n")
		self
	end

	def export_binary(binary_file) 
		h = open(binary_file,"wb")
		@data.each { |b| h.write(b.chr) }
		self 
	end
end

# *****************************************************************************
#
# 						Monitor ROM with patches
#
# *****************************************************************************

class MonitorROM < StandardROM
end 

if __FILE__ == $0 
	StandardROM.new("vtechv20.u12").export_include("_v20_rom.h")
end