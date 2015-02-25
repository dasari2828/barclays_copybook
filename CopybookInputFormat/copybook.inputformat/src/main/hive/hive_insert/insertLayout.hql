add jar ${mainFrameJar};
use default;

insert into table ${insertTo} select * from ${insertFrom};