## Mixed Mode example for a EUTelescope analysis

```
jobsub -c config-mixed.cfg -csv runlist.csv -g noisypixelmasker 315
jobsub -c config-mixed.cfg -csv runlist.csv -g clustering 315

jobsub -c config-mixed.cfg -csv runlist.csv -g hitmaker 315
jobsub -c config-mixed.cfg -csv runlist.csv -g aligngbl 315
jobsub -c config-mixed.cfg -csv runlist.csv -g aligngbl 315
jobsub -c config-mixed.cfg -csv runlist.csv -g aligngbl 315
jobsub -c config-mixed.cfg -csv runlist.csv -g trackgbltriplet 315
```
