const electron = require('electron');
const app = electron.app;
const BrowserWindow = electron.BrowserWindow;

const Protocol = require('./protocol');

const protocol = new Protocol();

process.on('uncaughtException', function (err) {
  console.error(err.stack);
  app.quit();
});
 
app.on('ready', () => {
  const mainWindow = new BrowserWindow({
    height: 650,
    width: 1200,
  });

  const url = require('url').format({
    protocol: 'file',
    slashes: true,
    pathname: require('path').join(__dirname, 'static', 'app.html')
  });
 
  mainWindow.loadURL(url);
});
