# Job Submission on the NAF

## BIRD (HTCondor)

Links:
- https://confluence.desy.de/pages/viewpage.action?pageId=67639562


Workflow of HTCondor now implemented in jobsub.py (need still more validation and afterwards clean up)

How to run the example (it is copy of gbl_local):

jobsub -c config.cfg -csv runlist.csv --htc condorparameters.cfg converter 117