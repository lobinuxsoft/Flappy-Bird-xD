set ProjectDir=%~1
set TargetDir=%~2

xcopy "%ProjectDir%resources\" "%TargetDir%resources\" /E /Y