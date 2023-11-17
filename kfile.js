let project = new Project("Game");

project.kore = false;

project.addFile("Game/**");

project.setDebugDir("Deployment");

project.addIncludeDir("./Engin/includes");
project.addIncludeDir("./Game/Includes");

project.flatten();

const otherproj = await project.addProject("Engin");
otherproj.addProvider(project, true);

resolve(project);