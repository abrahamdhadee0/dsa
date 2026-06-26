import simpleGit from 'simple-git';
import jsonfile from 'jsonfile';

const git = simpleGit();
const FILE = './data.json';

async function run() {
  const now = new Date();

  // write something new so git detects a change
  await jsonfile.writeFile(FILE, {
    lastRun: now.toISOString()
  });

  await git.add([FILE]);

  await git.commit(
    'daily update',
    undefined,
    {
      '--date': now.toISOString()
    }
  );

  await git.push();

  console.log('✅ committed for today:', now.toDateString());
}

run().catch(console.error);
