let project = new Project("Solomons Key");

project.kore = false;

project.addFile("Game/**");

project.setDebugDir("Deployment");

project.addIncludeDir("./Engin/includes");

project.flatten();

const otherproj = await project.addProject("Engin");
otherproj.addProvider(project, true);

resolve(project);