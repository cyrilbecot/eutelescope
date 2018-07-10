## Mixed Mode example for a EUTelescope analysis

```
jobsub -c config.cfg -csv runlist.csv -g converter 117
jobsub -c config.cfg -csv runlist.csv -g clustering 117
jobsub -c config.cfg -csv runlist.csv -g hitmaker 117
jobsub -c config.cfg -csv runlist.csv -g aligngbl 117
jobsub -c config.cfg -csv runlist.csv -g aligngbl2 117
jobsub -c config.cfg -csv runlist.csv -g aligngbl3 117
jobsub -c config.cfg -csv runlist.csv -g trackgbltriplet 117
```
