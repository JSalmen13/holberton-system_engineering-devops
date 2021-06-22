# 0x19. Postmortem
The goal of this exercise was to practice writing a postmortem for a system outage or issue. The postmortem was for a made-up issue, and it followed a conventional postmortem structure to describe the issues, their resolutions, timelines, and future preventative actions.

## Issue Summary
Last week, an outage was discovered that lasted one day, from 9/10 7:55 PT to 9/11 6:00 PT. Our primary online service's web server was unable to deliver the web material that was requested, resulting in customer complaints and a lower visitor volume for the whole week. Other portions of the website, which were hosted on other web servers, were unaffected by the outage, which affected 80 percent of visitors. The main cause appears to be related to a nonexistent symlink in the Apache 2 web server application's configuration files. In this settings file, there appears to be a typo.

## Root Cause
On Monday, September 10th, at 7:55 p.m. PT, the problem was initially discovered. It was discovered that there was an issue with the settings and that some files did not exist and could not be retrieved after executing many STRACE test calls on an HTTP GET request and watching the 500 status code of the response. The problem was caused by a mistake in the Apache2 settings file, where the symbolic link filename was missing. The wp-settings.php file was pointing to locale-wp.phpp when the real file in the /var/www/html/locale/ folder was named locale-wp.php. The problem was resolved by editing the wp-settings.php file and changing the typo in the locale-wp.php file from.phpp to.php.

## Corrective Measures
- Set up request logging to make it easier to see what's being transmitted over the network.
- Rewrite the program to ensure that the os.getenv method in Python returns a string that is longer than zero.
