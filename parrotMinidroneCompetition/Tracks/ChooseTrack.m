d = dir('Tracks');
fn = {d.name};
fn(1:3)=[];
%%
[indx,~] = listdlg('PromptString',{'Select a Track.',...
    'Only one file can be selected at a time.',''},...
    'SelectionMode','single','ListString',fn);
run(fn(indx));

clear fn d