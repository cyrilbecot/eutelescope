#!/bin/bash
source /nfs/dust/atlas/user/dreyling/eutelescope/v01-19-02/Eutelescope/master/build_env.sh
sleep 1
cd /nfs/dust/atlas/user/dreyling/eutelescope/v01-19-02/Eutelescope/master/jobsub/examples/gbl_local
jobsub -c config.cfg -csv runlist.csv -g converter 117
