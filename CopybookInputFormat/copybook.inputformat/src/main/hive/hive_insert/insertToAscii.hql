ADD JAR ${mainFrameJar};
insert into table ${insertTo} select * from ${insertFrom};