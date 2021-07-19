# OllyDbg-Argfile-Docs
Documentation on the *undocumented* OllyDbg v2.01 `.arg` file, allowing definition of structures, functions, enumerations, etc.

Initial information on the `.arg` file was found thanks to [this StackOverflow answer](https://reverseengineering.stackexchange.com/a/11911/36150). Remaining information has been discovered through reverse engineering with Ghidra and extensive trial-and-error testing. There is still plenty that is not fully known, or understood in the slightest.


## Basics

### Filename

Files **must** use the `.arg` extension, and be located in the same folder as OllyDbg (*or working directory?*).

The filename `common.arg` is loaded on startup of OllyDbg, and its definitions are made available for all debugged process.

For everything else, the filename `<processname>.arg` must be used, which will presumably load when attaching or starting a new debugging session.


### Troubleshooting

It's recommended to use `common.arg` when frequently troubleshooting syntax errors or mistakes, as it is loaded immediately on startup of OllyDbg.

Errors produced when loading an `.arg` file will be shown in the **Log** window (**View > Log**) in OllyDbg. Parsing of the file will stop the moment an error occurs, which will then be reported along with the line number.

<details><summary>See Log Examples</summary>

**Success:**
```log
 OllyDbg v2.01
 Loading function descriptions from 'common.arg'
   216 constants, 42 structures, 16 types, 3 functions, 2 data blocks
   Total size of known data is 1550920 bytes
```

**Error:**
```diff
 OllyDbg v2.01
 Loading function descriptions from 'common.arg'
   216 constants, 42 structures, 16 types, 3 functions, 2 data blocks
-  Line 170. Extra characters on line
```
</details>

## See also

### External links

* [OllyDbg v2.01](http://www.ollydbg.de/)
* [StackOverflow answer](https://reverseengineering.stackexchange.com/a/11911/36150)
