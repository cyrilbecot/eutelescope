# Mixed Mode example for a EUTelescope analysis

## Standard event building (EUDET mode)



```
jobsub -c config-mixed.cfg -csv runlist.csv -g noisypixelmasker 315
jobsub -c config-mixed.cfg -csv runlist.csv -g clustering 315

jobsub -c config-mixed.cfg -csv runlist.csv -g hitmaker 315
jobsub -c config-mixed.cfg -csv runlist.csv -g aligngbl 315
jobsub -c config-mixed.cfg -csv runlist.csv -g aligngbl 315
jobsub -c config-mixed.cfg -csv runlist.csv -g aligngbl 315
jobsub -c config-mixed.cfg -csv runlist.csv -g trackgbltriplet 315
```
jobsub -c config-standard.cfg -csv runlist.csv -g noisypixelmasker 315
jobsub -c config-standard.cfg -csv runlist.csv -g noisypixelmasker 315
