# WER

This allows you to delete arbitrary files on a non-admin account.

You can potentially delete cross-user data (delete files from an admin!) .... trigger dll hijacking ... delete folders in programdata and lock them to the current user (shown in PoC)..
delete drivers and cause a BSOD at start-up .. really fun thing to do with school computers.

Have fun... use demo for repro ... I won't explain how this works. Normally you don't have to restart/sign-out to trigger the vulnerable routine .. it just saves time .. there are ways to manually trigger it, I will leave that as an exercise for the reader.
