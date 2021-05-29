sudo pkill -1 runcf
sudo pkill -1 exec
sudo pkill -1 bridge
sudo pkill -1 stats
sudo pkill -1 frontend
sudo pkill -1 swload
sudo pkill -1 swman
sudo pkill -1 hwman
sudo pkill -1 statsman
sudo pkill -1 sync_master
sudo pkill -1 cmdman
sudo pkill -1 gnuplot

sudo pkill -15 runcf
sudo pkill -15 exec
sudo pkill -15 bridge
sudo pkill -15 stats
sudo pkill -15 frontend
sudo pkill -15 swload
sudo pkill -15 swman
sudo pkill -15 hwman
sudo pkill -15 statsman
sudo pkill -15 sync_master
sudo pkill -15 cmdman
sudo pkill -15 gnuplot

sudo pkill -9 runcf
sudo pkill -9 exec
sudo pkill -9 bridge
sudo pkill -9 stats
sudo pkill -9 frontend
sudo pkill -9 swload
sudo pkill -9 swman
sudo pkill -9 hwman
sudo pkill -9 statsman
sudo pkill -9 sync_master
sudo pkill -9 cmdman
sudo pkill -9 gnuplot

sudo runcf -f
sudo runcf -f
sudo runcf -f

sudo kill -9 $(ps -A -ostat,ppid | grep -e '[zZ]'| awk '{ print $2 }')
