#ifndef GITHUB_V3_H
#define GITHUB_V3_H

struct github_v3_git_op_file {
  char *path;
  char *sha;
};

extern struct github_v3_git_op*
github_v3_git_op_init(char *username, char *token, char *repo_config);

extern char * github_v3_git_op_update_my_fork(struct github_v3_git_op *d);
extern char* github_v3_git_op_get_head_commit(struct github_v3_git_op *data);
extern char* github_v3_git_op_get_tree_sha(struct github_v3_git_op *data, char *commit_sha);
extern void github_v3_git_op_create_blobs(struct github_v3_git_op *data, struct github_v3_git_op_file **files);
extern char* github_v3_git_op_create_tree(struct github_v3_git_op *data, char *base_tree_sha, struct github_v3_git_op_file **files);
extern char* github_v3_git_op_create_a_commit(struct github_v3_git_op *data, char *tree_sha, char *parent_commit_sha, char *commit_msg);
extern void github_v3_git_op_create_a_branch(struct github_v3_git_op *data, char *head_commit_sha, char *branch);
extern void github_v3_git_op_update_a_commit(struct github_v3_git_op *d, char *branch, char *commit_sha);
extern void github_v3_git_op_create_a_pull_request(struct github_v3_git_op *d, char *branch, char *pull_msg);

#endif // GITHUB_V3_H
