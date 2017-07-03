# WER

This allows you to delete arbitrary files on a non-admin account. (I think its still unpatched.. havn't tested but should be)

You can potentially delete cross-user data (delete files from an admin!) .... trigger dll hijacking ... delete folders in programdata and lock them to the current user (shown in PoC)..
delete drivers and cause a BSOD at start-up .. really fun thing to do with school computers.

Have fun... use demo for repro ... I won't explain how this works. Normally you don't have to restart/sign-out to trigger the vulnerable routine .. it just saves time .. there are ways to manually trigger it, I will leave that as an exercise for the reader.

HOW TO USE:

At a basic level .. just drop setup.exe and Report.wer on the desktop ... drop lpe.exe in the start-up folder ... run setup.exe.. and either wait very long time .. or restart (or cause a higher privileged service to crash so WERMGR kicks in). Restarting might fail if services are crashing before LPE.exe opens... but there are all ways to solve this... use your creativity.




