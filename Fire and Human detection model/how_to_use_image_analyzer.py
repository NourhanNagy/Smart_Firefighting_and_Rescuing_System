from image_fire_analyzer import ImageAnalyzer
from PIL import Image

# image_to_use = Image.open(".\yolov5\data\images\zidane.jpg")
image_to_use = Image.open(".\yolov5\data\images\pr55_Bonfires05.jpeg")
xsize, ysize = image_to_use.size


# DO WHATEVER CODE YOU SEE FIT TO FETCH THE IMAGE FROM THE SOURCES YOU HAVE INTO EITHER 
# A FILE URL OR PIL IMAGE OBJECT TO PASS IT TO THE MODEL

image_analyzer_instance = ImageAnalyzer()

image_analyzer_instance.load_image(image_to_use,xsize,ysize)

# To know if there is any fire in this image
do_we_have_fire = image_analyzer_instance.is_fire_detected() # this is a boolean

# To know if there is any human in this image
do_we_have_human = image_analyzer_instance.is_human_detected() # this is a boolean


# To know which quadrant does the fire exist

quadrant_with_fire = image_analyzer_instance.locate_fire() # returns a value from 1 to 4


# DO WHAT EVER LOGIC YOU SEE FIT GIVEN THE INFORMATION YOU NOW KNOW

print(f"Do we have fire: {do_we_have_fire}")
print(f"Do we have human: {do_we_have_human}")
if do_we_have_fire:
    print(f"Quadrant with fire: {quadrant_with_fire}")
else:
    print(f"what will the result be: {quadrant_with_fire}")