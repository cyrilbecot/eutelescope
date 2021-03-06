/*
 *   This source code is part of the Eutelescope package of Marlin.
 *   You are free to use this source files for your own development as
 *   long as it stays in a public research context. You are not
 *   allowed to use it for commercial purpose. You must put this
 *   header with author names in all development based on this file.
 *
 */
#ifndef EUTELPEDEGEAR_H
#define EUTELPEDEGEAR_H

// built only if GEAR is available
#ifdef USE_GEAR
// eutelescope includes ".h"
#include "EUTelUtility.h"

// marlin includes ".h"
#include "marlin/Processor.h"

// lcio includes <.h>
#include <EVENT/LCEvent.h>
#include <EVENT/LCRunHeader.h>

// Eigen
#include <Eigen/Core>

// system includes <>
#include <string>
#include <vector>

namespace eutelescope {

  class EUTelPedeGEAR : public marlin::Processor {

  public:
    //! Returns a new instance of EUTelPedeGEAR
    /*! This method returns a new instance of this processor.  It is
     *  called by Marlin execution framework and it shouldn't be
     *  called/used by the final user.
     *
     *  @return a new EUTelPedeGEAR.
     */
    virtual Processor *newProcessor() { return new EUTelPedeGEAR; }

    //! Default constructor
    EUTelPedeGEAR();

    //! Called at the job beginning.
    /*! This is executed only once in the whole execution. It prints
     *  out the processor parameters and check that the GEAR
     *  environment is properly set up and accessible from Marlin.
     */
    virtual void init();

    //! Called for every run.
    /*! It is called for every run, and consequently the run counter
     *  is incremented. The geometry ID of the file is compared with
     *  the one provided by the GEAR geometry description. In case the
     *  two are different, the user is asked to decide to quit or to
     *  continue with a description that might be wrong.
     *
     *  @param run the LCRunHeader of the this current run
     */
    virtual void processRunHeader(LCRunHeader *run);

    //! Called every event
    /*! This is called for each event in the file. Each element of the
     *  pulse collection is scanned and the center of the cluster is
     *  translated into the external frame of reference thanks to the
     *  GEAR geometry description.
     *
     *  The cluster center might be calculate using a standard linear
     *  charge center of gravity algortihm or applying a more
     *  sophisticated non linear eta function. This behaviour is
     *  regulated by the user from the steering file.
     *
     *  @throw UnknownDataTypeException if the cluster type is unknown
     *
     *  @param evt the current LCEvent event as passed by the
     *  ProcessMgr
     */
    virtual void processEvent(LCEvent *evt);

    //! Called after data processing.
    /*! This method is called when the loop on events is
     *  finished.
     */
    virtual void end();

  protected:
    //! Ordered sensor ID
    /*! Within the processor all the loops are done up to _nPlanes and
     *  according to their position along the Z axis (beam axis).
     *
     *  This vector is containing the sensorID sorted according to the
     *  same rule.
     */
    std::vector<int> _orderedSensorID;
    std::vector<int> _orderedSensorID_wo_excluded;

    Utility::alignMode _alignMode;
	std::string _alignModeString;
    std::vector<double> _siPlaneZPosition;

    // parameters
    std::vector<unsigned int> _excludePlanes; // only for internal usage
    std::vector<int> _excludePlanes_sensorIDs;          // this is going to be
    // set by the user.
    std::vector<int> _FixedPlanes;           // only for internal usage
    std::vector<int> _FixedPlanes_sensorIDs; // this is going to be
    // set by the user.
    std::string _pedeSteerfileName;

	bool _rotateOldOffsetVec;

  private:
    //! Run number
    int _iRun;

    //! Event number
    int _iEvt;

    // Excluded planes
    int _nExcludePlanes;

    std::string _GEARFileSuffix;

    size_t _nPlanes;
  };

  //! A global instance of the processor
  EUTelPedeGEAR gEUTelPedeGEAR;
}
#endif
#endif
