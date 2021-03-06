/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

#ifndef __vtkPlusOpticalMarkerTracker_h
#define __vtkPlusOpticalMarkerTracker_h

// Local includes
#include "vtkPlusDataCollectionExport.h"
#include "vtkPlusDevice.h"

/*!
  \class vtkPlusOpticalMarkerTracker
  \brief Virtual device that tracks fiducial markers on the input channel in real time.
  \ingroup PlusLibDataCollection
*/
class vtkPlusDataCollectionExport vtkPlusOpticalMarkerTracker : public vtkPlusDevice
{
public:
  /*! Defines whether or not depth stream is used. */
  enum TRACKING_METHOD
  {
    TRACKING_OPTICAL,
    TRACKING_OPTICAL_AND_DEPTH
  };

  static vtkPlusOpticalMarkerTracker* New();
  vtkTypeMacro(vtkPlusOpticalMarkerTracker, vtkPlusDevice);
  virtual void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  /*! Read main config settings from XML. */
  virtual PlusStatus ReadConfiguration(vtkXMLDataElement*);

  /*! Write current main config settings to XML. */
  virtual PlusStatus WriteConfiguration(vtkXMLDataElement*);

  /*! Connect to the tracker hardware */
  PlusStatus InternalConnect();

  /*! Get an update from the tracking system and push the new transforms to the tools. */
  virtual PlusStatus InternalUpdate();

  /*! Verify the device has been correctly configured */
  virtual PlusStatus NotifyConfigured();

  /* This device is a virtual tracker. */
  virtual bool IsTracker() const { return true; }
  virtual bool IsVirtual() const { return true; }

protected:
  vtkPlusOpticalMarkerTracker();
  ~vtkPlusOpticalMarkerTracker();

  class vtkInternal;
  vtkInternal* Internal;

private:
  vtkPlusOpticalMarkerTracker(const vtkPlusOpticalMarkerTracker&);
  void operator=(const vtkPlusOpticalMarkerTracker&);
};

#endif