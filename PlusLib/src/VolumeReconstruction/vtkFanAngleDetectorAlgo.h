/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

#ifndef __vtkFanAngleDetectorAlgo_h
#define __vtkFanAngleDetectorAlgo_h

#include "PlusConfigure.h"

#include "vtkImageData.h"

/*!
  \class vtkFanAngleDetectorAlgo
  \brief Determines non-blank sector in the ultrasound image

  \sa vtkPasteSliceIntoVolume
  \ingroup PlusLibVolumeReconstruction
*/
class VTK_EXPORT vtkFanAngleDetectorAlgo : public vtkObject
{
public:

  static vtkFanAngleDetectorAlgo *New();
  vtkTypeMacro(vtkFanAngleDetectorAlgo, vtkObject);
  virtual void PrintSelf(ostream& os, vtkIndent indent);

    /*! Set input image */
  vtkSetObjectMacro(Image, vtkImageData); 
  /*! Get input image */
  vtkGetObjectMacro(Image, vtkImageData); 

  /*!
    Set the clip rectangle origin to apply to the image in pixel coordinates.
    Pixels outside the clip rectangle will not be pasted into the volume.
    The origin of the rectangle is at its corner that is closest to the image origin.
  */
  vtkSetVector2Macro(ClipRectangleOrigin,int);
  /*!
    Get the clip rectangle origin to apply to the image in pixel coordinates.
  */
  vtkGetVector2Macro(ClipRectangleOrigin,int);

  /*! Set the clip rectangle size in pixels */
  vtkSetVector2Macro(ClipRectangleSize,int);
  /*! Get the clip rectangle size in pixels */
  vtkGetVector2Macro(ClipRectangleSize,int);

  /*!
    Set fan-shaped clipping region for curvilinear probes.
    The origin of the fan is defined in the image coordinate system, in the input image physical coordinate system.
  */
  vtkSetVector2Macro(FanOrigin,double);
  /*! Get fan-shaped clipping region for curvilinear probes */
  vtkGetVector2Macro(FanOrigin,double);

  /*!
    Set the fan-shaped clipping region for curvilinear probes.
    Fan angles is a vector containing the maximum allowed angles of the two straight edge of the fan, in degrees.
  */
  vtkSetVector2Macro(MaxFanAnglesDeg,double);
  /*! Set the fan-shaped clipping region for curvilinear probes */
  vtkGetVector2Macro(MaxFanAnglesDeg,double);
  
  /*!
    Set the fan-shaped clipping region for curvilinear probes.
    Fan radius start is the minimum depth, in the input image physical coordinate system.
  */
  vtkSetMacro(FanRadiusStart,double);
  /*!
    Get the fan-shaped clipping region for curvilinear probes.
    Fan radius start is the minimum depth, in the input image physical coordinate system.
  */
  vtkGetMacro(FanRadiusStart,double);

  /*!
    Set the fan-shaped clipping region for curvilinear probes.
    Fan radius stopt is the maximum depth, in the input image physical coordinate system.
  */
  vtkSetMacro(FanRadiusStop,double);
  /*!
    Get the fan-shaped clipping region for curvilinear probes.
    Fan radius start is the maximum depth, in the input image physical coordinate system.
  */
  vtkGetMacro(FanRadiusStop,double);

  /*! Compute angles */
  void Update();

  /*! Output detected fan angles */
  vtkSetVector2Macro(DetectedFanAnglesDeg,double);
  vtkGetVector2Macro(DetectedFanAnglesDeg,double);

  /*! Returns true if non-blank (not black) area is found in the image */
  vtkGetMacro(IsFrameEmpty,bool);
  
protected: 
  vtkFanAngleDetectorAlgo();
  virtual ~vtkFanAngleDetectorAlgo();

  vtkImageData* Image;

  double MaxFanAnglesDeg[2];

  double DetectedFanAnglesDeg[2];

  // Clipping parameters
  int ClipRectangleOrigin[2];
  int ClipRectangleSize[2];
  double FanOrigin[2]; // in the input image coordinate system (in physical coordinates; but Plus always uses 1.0 spacing, so these are effectively in pixels)
  double FanRadiusStart; // in the input image coordinate system (in physical coordinates; but Plus always uses 1.0 spacing, so the value is effectively in pixels)
  double FanRadiusStop; // in the input image coordinate system (in physical coordinates; but Plus always uses 1.0 spacing, so the value effectively in pixels)

  bool IsFrameEmpty;

private: 
  vtkFanAngleDetectorAlgo(const vtkFanAngleDetectorAlgo&);  // Not implemented.
  void operator=(const vtkFanAngleDetectorAlgo&);  // Not implemented.
}; 

#endif
