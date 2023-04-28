import torch

class ImageAnalyzer:
  """
  this class is used to detect fire in an image as well as the existence of
  human through this fire
  """
  
  def __init__(self, path_to_yolo= "./yolov5",
               path_to_fire_model="./yolov5/models/fire.pt", 
               path_to_yolo_model = "./yolov5/models/yolov5n.pt",
               fire_confidence = 0.4,
               yolo_confidence = 0.6):
    """
    initializes the models for detection
    Make sure to load the image first thing using load_image
    """
    self._fire_model = torch.hub.load(path_to_yolo, "custom", 
                                     path= path_to_fire_model, 
                                     source="local")
    self._yolo_model = torch.hub.load(path_to_yolo,"custom",
                                     path=path_to_yolo_model, 
                                     source="local")
    self.image = None
    self.image_width = None
    self.image_height = None
    self._fire_confidence = fire_confidence
    self._generic_confidence = yolo_confidence
    
  def load_image(self, img_source, width, height):
    """
    this method loads the image from a file or PIL (python image library) image object 
    and specify its width and height

    this method needs to be invoked first to tell the model which image to work on
    """
    self.image = img_source
    self.image_width = width
    self.image_height = height
    return self

  def get_fire_model(self):
    """
    Do not touch
    gets the yolov5 fire model that is trained for detecting fires
    """
    return self._fire_model

  def get_generic_model(self):
    """
    Do not touch
    gets the yolov5 detection model that is trained for detecting objects and humans
    """
    return self._yolo_model

  def is_fire_detected(self):
    """
    this method tells u whether there is a fire in the image that you loaded earlier
    returns true or false
    """
    if self.image is None:
      return False
    if self._fire_model is None:
      return False
    if self.detect_fire() is not None:
      return True
    return False

  def detect_fire(self):
    """
    Do Not touch
    This method is used internally to run the fire detection
    returns data that is understandable by the functions that are utilizing it
    not human readable.

    If curious please refer to the documentation of YOLOv5
    """
    if self.image is None:
      return None
    if self._fire_model is None:
      return None
    data_frame = self._fire_model(self.image).pandas().xyxy[0]
    filtered_data_frame = (data_frame[ data_frame["confidence"]> self._fire_confidence ])
    if filtered_data_frame.shape[0] > 0:
      return filtered_data_frame.iloc[0]
    else:
      return None

  def is_human_detected(self):
    """
    this method tells u whether there is a human in the image that you loaded earlier
    returns true or false
    """
    if self.image is None:
      return False
    if self._yolo_model is None:
      return False
    if self.detect_human() is not None:
      return True
    return False

  def detect_human(self):
    """
    Do Not touch
    This method is used internally to run the fire detection
    returns data that is understandable by the functions that are utilizing it
    not human readable.

    If curious please refer to the documentation of YOLOv5
    """
    if self.image is None:
      return None
    if self._yolo_model is None:
      return None
    data_frame = self._yolo_model(self.image).pandas().xyxy[0]
    filtered_data_frame = (data_frame[ data_frame["confidence"]> self._generic_confidence ])
    if filtered_data_frame.shape[0] > 0:
      return filtered_data_frame.iloc[0]
    else:
      return None

  def get_center(self, xmin,ymin,xmax,ymax):
    """
    internal function that calculates the center given coordinates
    """
    return (xmin + (xmax-xmin)/2), (ymin+(ymax - ymin)/2)

  def find_quadrant(self, x,y):
    """
    This method is utilized internally do not edit
    """
    if self.image_width/2 < x:
      # right quadrants 1,4
      if self.image_height/2<y:
        return 1
      else:
        return 4
    else:
      # left quadrants 2,3
      if self.image_height/2 <y:
        return 2
      else:
        return 3

  def locate_fire(self):
    """
    this method returns which quadrant of the image containing fire
    returns 1,2,3,4 representing quadrants
    """
    if self.image is None:
      return (-1, -1)
    if self._fire_model is None:
      return (-1, -1)
    if self.is_fire_detected() == False:
      return (-1, -1)
    data_points = self.detect_fire()
    xmin = data_points[0]
    ymin = data_points[1]
    xmax = data_points[2]
    ymax = data_points[3]
    xcenter, ycenter = self.get_center(xmin=xmin,ymin=ymin,xmax=xmax,ymax=ymax)
    return self.find_quadrant(x=xcenter,y=ycenter)

